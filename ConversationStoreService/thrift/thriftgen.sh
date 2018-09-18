rm gen-cpp/*
../../../contribs/ApacheThrift/bin/thrift -r -gen cpp conversationstore.thrift
../../../contribs/ApacheThrift/bin/thrift -r -gen go  conversationstore.thrift
rm gen-cpp/*skele*
