Программа ```main.cpp``` предоставляет возможности текстового редактора. В редакторе есть такие возможности:
- переместить курсор на строчку вниз (down)
- переместить курсор на строчку вверх (up)
- включить выделение строк (shift)
	- операции up, down при зажатом shift выделяют строку
- вырезать текущую строку или выделенные строки, при зажатом shift, в буфер обмена (cut)
- копировать текущую строку или выделенные строки, при зажатом shift, в буфер обмена с отменой выделения (copy)
- вставить строку из буфера перед текущей строкой (paste)

Примеры:

1. Ввод

	```
	hello
	salut
	privet
	shalom

	down
	cut
	down
	paste
	```
	Вывод
	
	```
	hello
	privet
	salut
	shalom
	```
2. Ввод
	```
	hello
	salut
	privet
	shalom
	salam

	down
	down
	down
	shift
	up
	up
	up
	cut
	down
	paste
	```
	Вывод
	```
	shalom
	hello
	salut
	privet
	salam
	```