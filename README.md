<h2>Using Unix Signals ! 📡</h2>

<h3>About</h3>

This is a server/client system that uses UNIX signals for communication. 
<br>
The server displays its PID and receives decrypted signals as characters, while the client encrypts messages and sends true/false signals using SIGUSR1 or SIGUSR2 to the server's PID.

<h3>How to use</h3>
<li>Run make</li>

```
make 
```

<li>Run the server and copy its PID</li>

```
./server 
```

<li>Run the client in another terminal and pass the server's PID as argument</li>

```
./client <PID>
```

<li>Grab a cup of coffee and have a little chit chat 😎</li>
