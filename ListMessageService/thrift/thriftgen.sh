rm gen-cpp/*
../../../../contribs/ApacheThrift/bin/thrift -r -gen cpp listmessageservice.thrift
../../../../contribs/ApacheThrift/bin/thrift -r -gen go  listmessageservice.thrift
rm gen-cpp/*skele*
