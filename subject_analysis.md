# 과제분석

## 과제 목적

 The object of this project is for you to create a simple shell.

 Windows가 존재하지 않던 시절 사람들이 마주했던 문제들과 마주하기.


## 과제에서 배울 것

 1. 프로세스(proceses)
   a. IPC(Inter-Process Communication)

 2. 파일 식별자(file descriptors)
 3. 허용 함수들이 어떤 일을 하는지


### 허용 함수

```
readline, rl_on_new_line, rl_replace_line,
rl_redisplay, add_history, printf, malloc, free,
write, open, read, close, fork, wait, waitpid,
wait3, wait4, signal, kill, exit, getcwd, chdir,
stat, lstat, fstat, unlink, execve, dup, dup2,
pipe, opendir, readdir, closedir, strerror, errno,
isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr,
tcgetattr, tgetent, tgetflag, tgetnum, tgetstr,
tgoto, tputs
```

### 참고하면 좋을 링크

- [bash manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/)

### 깃브런치 전략
- [트렁크 기반 개발](https://code-masterjung.tistory.com/73)