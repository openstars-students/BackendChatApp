namespace cpp OpenStars.Core.I64ToI64Set.Data
namespace java openstars.i64toi64set.thrift.data

typedef i64 TKey
typedef i64 TItem

struct TValue {
	1: required list<TItem> items;
}
