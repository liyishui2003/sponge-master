#include "stream_reassembler.hh"
#include <iostream>
// Dummy implementation of a stream reassembler.

// For Lab 1, please replace with a real implementation that passes the
// automated checks run by `make check_lab1`.

// You will need to add private members to the class declaration in `stream_reassembler.hh`

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

/*
size_t _capacity;    //!< The maximum number of bytes
    set<dataNode>s;
    map<size_t,int>submited;
    ByteStream _output;  //!< The reassembled in-order byte stream
    size_t reassembleByte = 0;
    bool isEof = false;
*/
StreamReassembler::StreamReassembler(const size_t capacity) 
        : _capacity(capacity), 
          store(), 
          _output(capacity) {
        // 构造函数体可以为空，因为成员变量都已在初始化列表中初始化
    }

//! \details This function accepts a substring (aka a segment) of bytes,
//! possibly out-of-order, from the logical stream, and assembles any newly
//! contiguous substrings and writes them into the output stream in order.

void StreamReassembler::push_substring(const string &data, const size_t index, const bool eof) {
    
    size_t len = data.length();
    for(size_t i = 0;i < len;i++){
        if(store.find(index+i) != store.end() ) {}
        else store[index+i] = data[i],unAssemble++;
    }

    if(eof == true) lastIndex = index + len;

    while(store.find(reassembleByte) != store.end()){
        _output.write(std::string(1,store[reassembleByte]));
        unAssemble--;
        reassembleByte++;
    }

    if(lastIndex != -1 && static_cast<int>(reassembleByte) == lastIndex ){
        _output.end_input();
    }
    
}

size_t StreamReassembler::unassembled_bytes() const { return unAssemble; }

// myTodo
bool StreamReassembler::empty() const { return unAssemble == 0; }
