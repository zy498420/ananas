
#ifndef BERT_ACCEPTOR_H
#define BERT_ACCEPTOR_H

#include "Socket.h"
#include "EventLoop.h"

namespace ananas
{
namespace internal
{

class Acceptor : public EventSource
{
public:
    explicit
    Acceptor(EventLoop* loop);
    ~Acceptor();
    
    Acceptor(const Acceptor& ) = delete;
    void operator= (const Acceptor& ) = delete;

    void SetNewConnCallback(EventLoop::NewConnCallback cb);
    bool Bind(const SocketAddr& addr);
        
    int Identifier() const override;
    bool HandleReadEvent() override;
    bool HandleWriteEvent() override;
    void HandleErrorEvent() override;

private:
    int _Accept();

    SocketAddr peer_;
    int localSock_;
    uint16_t localPort_;

    EventLoop* loop_; // which loop belong to

    //register msg callback and on connect callback for conn
    EventLoop::NewConnCallback newConnCallback_;

    static const int kListenQueue;
};

} // end namespace internal
} // end namespace ananas

#endif

