use std::io::{self, Write, Read};
use std::net::TcpStream;

fn main() {
    let mut stream = TcpStream::connect("127.0.0.1:8080").unwrap();
    println!("Connected");

    loop {
        print!("> ");
        io::stdout().flush().unwrap();

        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let input = input.trim();
        if input == "exit" { break; }

        stream.write_all(input.as_bytes()).unwrap();

        let mut buffer = [0u8; 1024];
        let n = stream.read(&mut buffer).unwrap();
        println!("Echo: {}", String::from_utf8_lossy(&buffer[..n]));
    }
}
