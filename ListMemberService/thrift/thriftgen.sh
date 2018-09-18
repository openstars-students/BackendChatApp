rm gen-cpp/*
../../../../contribs/ApacheThrift/bin/thrift -r -gen cpp listmemberservice.thrift
../../../../contribs/ApacheThrift/bin/thrift -r -gen go  listmemberservice.thrift
rm gen-cpp/*skele*
