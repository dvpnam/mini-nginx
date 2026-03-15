# Mini Nginx (C)

A minimal HTTP/1.1 web server written in C (~400 LOC).

## Features

- TCP socket server
- HTTP request parsing
- static file serving
- Content-Type detection
- Content-Length header
- directory index (/ → index.html)
- 404 error handling
- multi-threaded client handling
- request logging

## Architecture

browser
   ↓
TCP socket
   ↓
HTTP parser
   ↓
file handler
   ↓
static file

## Build

make

## Run

./mini-nginx

Server runs on:

http://localhost:8080

## Benchmark

wrk -t4 -c100 -d10s http://localhost:8080

Requests/sec:    764.34
Transfer/sec:    328.32KB

## Project Structure

mini-nginx
├── server.c
├── http_parser.c
├── http_parser.h
├── file_handler.c
├── file_handler.h
├── Makefile
├── README.md
├── .gitignore
└── www
    ├── index.html
    ├── style.css
    └── firewatch.jpg
