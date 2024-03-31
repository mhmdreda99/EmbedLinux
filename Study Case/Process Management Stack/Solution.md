# Case Study Solution

To monitor the CPU load of your process, you can use the `top` command in Linux. This command provides a dynamic real-time view of the running system. To monitor a specific process, you can use the `-p` option followed by the process ID.

```bash
top -p [process_id]
```

To generate a core dump for your process, you need to enable core dumping in your environment and then send an appropriate signal to your process. Here's how you can do it:

1. Enable core dumping:

```bash
ulimit -c unlimited
```

2. Set the core pattern. This pattern determines the name of the core dump file:

```bash
sudo sysctl -w kernel.core_pattern=./core.%e.%p.%t
```

3. Run your process. If you don't know the process id (pid), you can find it by using ```pgrep``` or ```ps``` command:

  ```./process```

4. Find the process id (pid):

    ```pgrep process```

1. Send a SIGABRT signal to your process. This will terminate the process and generate a core dump:
   ```kill -SIGABRT [pid]```

After these steps, you should have a core dump file in your current directory. You can analyze this file with a debugger like gdb:

   ```gdb process core```
