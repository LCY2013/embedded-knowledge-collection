# linux process
- [process概念](#process概念)
- [process命令](#linux进程命令)

## process概念
- 进程有独立的地址空间，进程间的数据不共享。
- Linux为每个进程创建task_struct结构体，用于存储进程信息。
- 每个进程都参与内核调度，进程的调度是以时间片为单位的，互不影响。

## linux进程命令
- [ps](#ps)
- [top](#top)
- [nice](#nice)
- [htop](#htop)
- [kill](#kill)
- [killall](#killall)
- [jobs](#jobs)
- [fg、bg](#fgbg)
- [/proc](#/proc)

### ps
ps 命令用于显示当前进程的状态。
```bash
# 显示当前进程
ps -ef | more
# 显示当前进程树
ps -ejH
# 显示当前进程树
ps axjf
# 显示当前进程树
pstree -p
# 显示当前进程加上状态
ps -aux
```

### top
top 命令用于显示当前系统中各个进程的资源占用状况，包括进程 ID、内存占用率、CPU 占用率等。
```bash
# 显示当前进程
top
# 切换到进程
p
# 切换到线程
H
# 切换到用户
u
# 切换到内存
m
# 切换到 CPU
P
# 切换到时间
T
# 切换到累计 CPU
t
# 切换到累计时间
W
# 切换到累计内存
M
# 切换到累计 IO
I
```

### nice
nice 命令用于调整进程的优先级。
```bash
# 显示设置当前进程优先级
nice -n 19 ./test
# 设置运行中的进程优先级
renice -n 19 -p PID
```

### htop
htop 命令用于显示当前系统中各个进程的资源占用状况，包括进程 ID、内存占用率、CPU 占用率等。
```bash
# 显示当前进程
htop
# 常用htop命令如下
F1	显示帮助
F2	设置
F3	搜索
```

### kill
kill 命令用于终止进程。
```bash
# 终止进程
kill -9 PID
# kill 命令的常用信号如下
1	HUP (hang up)	终端断线
2	INT (interrupt)	中断（同 Ctrl + C）
3	QUIT (quit)	退出（同 Ctrl + \）
9	KILL (non-catchable, non-ignorable kill)	强制终止
15	TERM (software termination signal)	终止（同 kill）
```

### killall
killall 命令用于终止进程。
```bash
# 终止进程
killall -9 test
# killall 命令的常用信号如下
1	HUP (hang up)	终端断线
2	INT (interrupt)	中断（同 Ctrl + C）
3	QUIT (quit)	退出（同 Ctrl + \）
9	KILL (non-catchable, non-ignorable kill)	强制终止
15	TERM (software termination signal)	终止（同 kill） 
```

### jobs
jobs 命令用于显示当前进程。
```bash
# 显示当前job进程
jobs
# 常用jobs命令如下
jobs -l	显示所有进程
jobs -r	显示运行中的进程
jobs -s	显示已停止的进程
```

### fgbg
fg 命令用于将后台进程切换到前台。
```bash
# 将后台进程切换到前台
fg %id
# 常用fg命令如下
fg %id	将后台进程切换到前台
# 前台进程变后台进程
Ctrl + Z
# 后台进程运行起来
bg %id
# 进程执行后台运行
./test &
```

### /proc
/proc 目录用于存储当前系统中的进程信息。
```bash
# 显示当前进程信息
cat /proc/PID/status
# 显示当前进程任务信息
cat /proc/PID/task/PID/status
# 显示当前文件描述符信息
cat /proc/PID/fd
# 显示当前进程环境变量信息
cat /proc/PID/environ
# 显示当前进程内存信息
cat /proc/PID/maps
```



