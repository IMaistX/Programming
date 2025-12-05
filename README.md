# Programming
 ![alt text](image.png)
Находимся на ветке main
Git log вывел коммит с хэшем, автора и дату.
После создания файла. В Git status нас просит добавить файл в область stage.
После добавления в stage, git status изменился на Changes not staged for commit: modified: sort.c.
 ![alt text](image-1.png)
 ![alt text](image-2.png)
 ![alt text](image-3.png)
Журнал Log показывает все коммиты.
 ![alt text](image-4.png)
Вторая часть задания, ветки.
 ![alt text](image-5.png)
После переключения на другую ветку, git status показывает на какой мы ветке.
Кода мы вернулись на ветку main, и использовали git log --oneline –graph, в log нет коммитов из mybranch.
 ![alt text](image-6.png)
 ![alt text](image-7.png)
Наш файл file2.txt пропал.
 ![alt text](image-8.png)

На оценку 4.
![alt text](image-9.png)
Git giff  показывает что изменилось в файле sort.c
![alt text](image-10.png)
 git diff –staged пустой
![alt text](image-11.png)
После добавления файла в staged, git diff становится пустым, а git diff –staged показывает изме5нения в файле.
После удаления числа git diff показывает только что удаленное число (красным), так как это новое изменение еще не в staged. А git diff –staged не изменился, так как изменение еще не в staged.
![alt text](image-12.png)
![alt text](image-13.png)
Теперь все изменения только в not staged.
![alt text](image-14.png)
![alt text](image-15.png)

После команды git restore sort.c  Sort.c выглядит так(т.е. наша строка printf(“hello git\n”) пропала):
![alt text](image-16.png)
![alt text](image-17.png)
Git status советует нам запушить на удаленный репо ветку.
![alt text](image-18.png)

2 Часть
![alt text](image-19.png)
Git status показывает, что ма на ветке feature/uppercase
![alt text](image-20.png)
![alt text](image-21.png)
Когда мы перейдем на главную ветку cat будет выводить hello, после объединения веток будет HELLO.
![alt text](image-22.png)
![alt text](image-23.png)
![alt text](image-24.png)

На оценку 5.
![alt text](image-25.png)
![alt text](image-26.png)
![alt text](image-27.png)
![alt text](image-28.png)
![alt text](image-29.png)
![alt text](image-30.png)
![alt text](image-31.png)
![alt text](image-32.png)
![alt text](image-33.png)
![alt text](image-34.png)
![alt text](image-35.png)