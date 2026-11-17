# files created with 0777
# file1 is using umask(000)
# file2 is using umask(007)

student@linux:~/reuvenTemp/EmbeddedExercises$ ll
total 0
drwxr-xr-x. 2 student student 136 Nov 17 11:06 exFiles
drwxr-xr-x. 2 student student  34 Nov 16 19:52 exPatch
drwxr-xr-x. 2 student student  42 Nov 17 13:22 exUmask
-rwxrwxrwx. 1 student student   0 Nov 17 13:22 file1
-rwxrwx---. 1 student student   0 Nov 17 13:22 file2