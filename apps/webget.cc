#include "socket.hh"
#include "util.hh"

#include <cstdlib>
#include <iostream>

using namespace std;

void get_URL(const string &host, const string &path) {
/*
    Address address = Address(host,"80");
    
    TCPSocket tcpSock = TCPSocket( );
    
    tcpSock.connect(address);

    std::string request="GET "+path+" "+"HTTP/1.1\r\n"+
    "Host: "+host+"\r\n"+
    "Connection: close\r\n\r\n";
  
    tcpSock.write(request);
    
    tcpSock.shutdown(SHUT_WR);
    
    while ( tcpSock.eof() == false )
    {
        std::string str;
        tcpSock.read(str);
        cerr << str << '\n';
    }
    
    tcpSock.close();
    
    cerr << "Function called: get_URL(" << host << ", " << path << ").\n";
*/
TCPSocket socket1;
    socket1.connect(Address(host,"80"));
    //这两个字段是类似上面2.1实验的
    auto request = "GET "+path+" HTTP/1.1\r\n"+"Host: "+host+"\r\n";
    auto request_close = "Connection: close\r\n\r\n";
    socket1.write(request + request_close);
    //获得响应
    while(!socket1.eof()){
        cout << socket1.read();
    }
    socket1.close();
}

int main(int argc, char *argv[]) {
    try {
        if (argc <= 0) {
            abort();  // For sticklers: don't try to access argv[0] if argc <= 0.
        }

        // The program takes two command-line arguments: the hostname and "path" part of the URL.
        // Print the usage message unless there are these two arguments (plus the program name
        // itself, so arg count = 3 in total).
        if (argc != 3) {
            cerr << "Usage: " << argv[0] << " HOST PATH\n";
            cerr << "\tExample: " << argv[0] << " stanford.edu /class/cs144\n";
            return EXIT_FAILURE;
        }

        // Get the command-line arguments.
        const string host = argv[1];
        const string path = argv[2];

        // Call the student-written function.
        get_URL(host, path);
    } catch (const exception &e) {
        cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
