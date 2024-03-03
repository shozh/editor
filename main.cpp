#include <iostream>
#include <fstream>

#include <list>
#include <string>
using namespace std;
 
int main() {
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");

	list<string> lines;
	string line;

	while (getline(ifs, line)) {
		if (line.empty())
			break;
 
		lines.push_back(line);
	}
 
	list<string>::iterator it = lines.begin();
	list<string> buf;
 
	bool shift_pressed = false;
	int shift_offset = 0;
	list<string>::iterator shift_it = lines.begin();
 
	while (ifs >> line) {

		if (line == "up") {
			if (it == lines.begin())
				continue;
 
			--it;
			if (shift_pressed)
				--shift_offset;
			else
				shift_it = it;
		} 
		else if (line == "down") {
			if (it == lines.end())
				continue;
 
			++it;
			if (shift_pressed)
				++shift_offset;
			else
				shift_it = it;

		} 
		else if (line == "cut") {
			if (shift_it == it && it == lines.end())
				continue;
 
			buf.clear();
 
			if (shift_it == it) {
				auto tmp = it;
				++it;
				buf.splice(buf.begin(), lines, tmp);
			} 
			else if (shift_offset < 0) {
				buf.splice(buf.begin(), lines, it, shift_it);
				it = shift_it;
			} 
			else if (shift_offset > 0)
				buf.splice(buf.begin(), lines, shift_it, it);
 
			shift_pressed = false;
			shift_it = it;
			shift_offset = 0;
		} 
		else if (line == "paste") {
			if (buf.empty())
				continue;
 
			if (shift_offset < 0)
				it = lines.erase(it, shift_it); 
			else if (shift_offset > 0)
				it = lines.erase(shift_it, it);
 
			lines.insert(it, buf.begin(), buf.end());
 
			shift_pressed = false;
			shift_it = it;
			shift_offset = 0;
		} 
		else if (line == "shift")
			shift_pressed = true;
		else if (line == "copy") {
			if (shift_it == it && it == lines.end())
				continue;
			
			buf.clear();
			if (shift_it == it)
				buf.push_back(*it);
			else if (shift_offset < 0)
				buf.insert(buf.begin(), it, shift_it);
			else if (shift_offset > 0)
				buf.insert(buf.begin(), shift_it, it);
			
			shift_pressed = false;
			shift_it = it;
			shift_offset = 0;	
		}
	}
 
	for (const auto& line: lines)
		ofs << line << endl;
	
	ofs.close();
	ifs.close();
	return 0;
}