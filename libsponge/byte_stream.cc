#include "byte_stream.hh"

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>
// Dummy implementation of a flow-controlled in-memory byte stream.

// For Lab 0, please replace with a real implementation that passes the
// automated checks run by `make check_lab0`.

// You will need to add private members to the class declaration in `byte_stream.hh`

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

ByteStream::ByteStream(const size_t Capacity):capacity(Capacity),buffer(){ 
   
}

size_t ByteStream::write(const string &data) {
    size_t len = data.length();
    size_t bufferLeft = capacity - buffer.size();
    size_t i;
    for(i = 0;i < len && bufferLeft;i++,bufferLeft--){
        writtenByte++;
        buffer.push_back(data[i]);
    }
    return i;
}

//! \param[in] len bytes will be copied from the output side of the buffer
string ByteStream::peek_output(const size_t len) const {
    
    size_t i;
    std::string s = "";
    for(i = 0;i < min(len,buffer.size());i++){
        s.push_back(buffer[i]);
    }
    return s;
}

//! \param[in] len bytes will be removed from the output side of the buffer
void ByteStream::pop_output(const size_t len) { 
    
    size_t i;
    for(i = 0;i < len;i++){
        readByte++;
        buffer.pop_front();
    }

}

void ByteStream::end_input() { endInput = true; }

bool ByteStream::input_ended() const { return endInput; }

size_t ByteStream::buffer_size() const { return buffer.size(); }

bool ByteStream::buffer_empty() const { return buffer.empty(); }

bool ByteStream::eof() const { return endInput && buffer.empty(); }

size_t ByteStream::bytes_written() const { return writtenByte; }

size_t ByteStream::bytes_read() const { return readByte; }

size_t ByteStream::remaining_capacity() const { return capacity - buffer.size(); }
