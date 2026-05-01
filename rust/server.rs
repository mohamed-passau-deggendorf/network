use std::io::{Read, Write};
use std::net::{TcpListener, TcpStream};

fn main() {
    let listener = TcpListener::bind("127.0.0.1:8080").unwrap();
    println!("Server waiting...");

    let mut stream = listener.incoming().next().unwrap().unwrap();
    println!("Client connected");

    let mut buffer = [0u8; 1024];

    loop {
        let bytes_read = stream.read(&mut buffer).unwrap();
        if bytes_read == 0 { break; }

        stream.write_all(&buffer[..bytes_read]).unwrap();
        stream.flush().unwrap();
    }
}
