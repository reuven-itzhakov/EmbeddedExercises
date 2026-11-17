### the output files
# testfilefirst is before the "X"
# testfilesecond is after the "X"

student@linux:~/EmbeddedExercises$ ll ./exFiles/
total 28
-rwxr-xr-x. 1 student student     `0` Nov 17 10:40 testfilefirst
-rwxr-xr-x. 1 student student  `1024` Nov 17 10:43 testfilesecond

### statPwd
prints to the stdout the "ls -s /etc/passwd" but using stat
and the prints the content of /etc/passwd
