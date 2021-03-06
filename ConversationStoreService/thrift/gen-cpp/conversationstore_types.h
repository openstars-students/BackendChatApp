/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef conversationstore_TYPES_H
#define conversationstore_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>


namespace OpenStars { namespace Platform { namespace ConversationStore {

struct TErrorCode {
  enum type {
    EGood = 0,
    ENotFound = -1,
    EUnknown = -2,
    EDataExisted = -3
  };
};

extern const std::map<int, const char*> _TErrorCode_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TErrorCode::type& val);

typedef int64_t TKey;

typedef class TConversationInfo TData;

class TConversationInfo;

class TDataResult;

class TListDataResult;

typedef struct _TConversationInfo__isset {
  _TConversationInfo__isset() : cid(false), cname(false), lastmessage(false), lasttime(false), status(false) {}
  bool cid :1;
  bool cname :1;
  bool lastmessage :1;
  bool lasttime :1;
  bool status :1;
} _TConversationInfo__isset;

class TConversationInfo : public virtual ::apache::thrift::TBase {
 public:

  TConversationInfo(const TConversationInfo&);
  TConversationInfo& operator=(const TConversationInfo&);
  TConversationInfo() : cid(0), cname(), lastmessage(0), lasttime(0), status(0) {
  }

  virtual ~TConversationInfo() throw();
  TKey cid;
  std::string cname;
  int64_t lastmessage;
  int64_t lasttime;
  int64_t status;

  _TConversationInfo__isset __isset;

  void __set_cid(const TKey val);

  void __set_cname(const std::string& val);

  void __set_lastmessage(const int64_t val);

  void __set_lasttime(const int64_t val);

  void __set_status(const int64_t val);

  bool operator == (const TConversationInfo & rhs) const
  {
    if (!(cid == rhs.cid))
      return false;
    if (!(cname == rhs.cname))
      return false;
    if (!(lastmessage == rhs.lastmessage))
      return false;
    if (!(lasttime == rhs.lasttime))
      return false;
    if (!(status == rhs.status))
      return false;
    return true;
  }
  bool operator != (const TConversationInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TConversationInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TConversationInfo &a, TConversationInfo &b);

std::ostream& operator<<(std::ostream& out, const TConversationInfo& obj);

typedef struct _TDataResult__isset {
  _TDataResult__isset() : errorCode(false), data(false) {}
  bool errorCode :1;
  bool data :1;
} _TDataResult__isset;

class TDataResult : public virtual ::apache::thrift::TBase {
 public:

  TDataResult(const TDataResult&);
  TDataResult& operator=(const TDataResult&);
  TDataResult() : errorCode((TErrorCode::type)0) {
  }

  virtual ~TDataResult() throw();
  TErrorCode::type errorCode;
  TConversationInfo data;

  _TDataResult__isset __isset;

  void __set_errorCode(const TErrorCode::type val);

  void __set_data(const TConversationInfo& val);

  bool operator == (const TDataResult & rhs) const
  {
    if (!(errorCode == rhs.errorCode))
      return false;
    if (__isset.data != rhs.__isset.data)
      return false;
    else if (__isset.data && !(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const TDataResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TDataResult &a, TDataResult &b);

std::ostream& operator<<(std::ostream& out, const TDataResult& obj);

typedef struct _TListDataResult__isset {
  _TListDataResult__isset() : errorCode(false), listconversation(false) {}
  bool errorCode :1;
  bool listconversation :1;
} _TListDataResult__isset;

class TListDataResult : public virtual ::apache::thrift::TBase {
 public:

  TListDataResult(const TListDataResult&);
  TListDataResult& operator=(const TListDataResult&);
  TListDataResult() : errorCode((TErrorCode::type)0) {
  }

  virtual ~TListDataResult() throw();
  TErrorCode::type errorCode;
  std::map<TKey, TConversationInfo>  listconversation;

  _TListDataResult__isset __isset;

  void __set_errorCode(const TErrorCode::type val);

  void __set_listconversation(const std::map<TKey, TConversationInfo> & val);

  bool operator == (const TListDataResult & rhs) const
  {
    if (!(errorCode == rhs.errorCode))
      return false;
    if (__isset.listconversation != rhs.__isset.listconversation)
      return false;
    else if (__isset.listconversation && !(listconversation == rhs.listconversation))
      return false;
    return true;
  }
  bool operator != (const TListDataResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TListDataResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TListDataResult &a, TListDataResult &b);

std::ostream& operator<<(std::ostream& out, const TListDataResult& obj);

}}} // namespace

#endif
