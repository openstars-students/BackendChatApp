rm gen-cpp/*
../../../contribs/ApacheThrift/bin/thrift -r -gen cpp messagestore.thrift
../../../contribs/ApacheThrift/bin/thrift -r -gen go  messagestore.thrift
rm gen-cpp/*skele*
