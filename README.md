**A minimal HTTP/1.1 web server written in C**

---

## ✨ Features

| Feature | Description |
|---|---|
| 🔌 **TCP Socket Server** | Raw socket-based connection handling |
| 🔍 **HTTP/1.1 Parser** | Request line & header parsing |
| 📁 **Static File Serving** | Serve files directly from disk |
| 🗂️ **MIME Detection** | Automatic `Content-Type` based on extension |
| 📏 **Content-Length** | Proper `Content-Length` header on all responses |
| 🏠 **Directory Index** | `/` resolves to `index.html` automatically |
| 🚫 **404 Handling** | Graceful not-found error responses |
| 🧵 **Multi-threaded** | Each client handled in its own thread |
| 📝 **Request Logging** | Method, path, and status logged to stdout |

---

## 🏗️ Architecture

```
  Browser
     │
     │  HTTP Request
     ▼
┌─────────────┐
│  TCP Socket │  ← Accept connections on :8080
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ HTTP Parser │  ← Parse method, path, headers
└──────┬──────┘
       │
       ▼
┌─────────────┐
│File Handler │  ← Resolve path → read file
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ Static File │  ← Stream response back to client
└─────────────┘
```

---

## 📂 Project Structure

```
mini-nginx/
├── server.c          # Entry point, socket setup, thread dispatch
├── http_parser.c     # HTTP request parsing logic
├── http_parser.h
├── file_handler.c    # File resolution & response building
├── file_handler.h
├── Makefile
├── README.md
├── .gitignore
└── www/              # Static files root
    ├── index.html
    ├── style.css
    └── firewatch.jpg
```

---

## 🚀 Getting Started

### Build

```bash
make
```

### Run

```bash
./mini-nginx
```

Server starts at:

```
http://localhost:8080
```

---

## 📊 Benchmark

Tested with [`wrk`](https://github.com/wg/wrk):

```bash
wrk -t4 -c100 -d10s http://localhost:8080
```

```
Running 10s test @ http://localhost:8080
  4 threads and 100 connections

  Requests/sec:    764.34
  Transfer/sec:    328.32KB
```

---

## 📄 License

MIT © mini-nginx contributors
