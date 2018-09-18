include "i64toi64set_shared.thrift"

namespace cpp OpenStars.Core.I64ToI64Set
namespace java openstars.i64toi64set.thrift

service TI64ToI64SetServiceR {
	i64toi64set_shared.TValue getValue(1: i64toi64set_shared.TKey key);
	i64toi64set_shared.TValue getValue_random(1: i64toi64set_shared.TKey key, 2: i32 aSize);
	i64toi64set_shared.TValue getValue_slice(1: i64toi64set_shared.TKey key, 2: i32 idxFrom, 3: i32 size);
	map<i64toi64set_shared.TKey, i64toi64set_shared.TValue> getValueMulti(1: list<i64toi64set_shared.TKey> keys);
	bool hasItem(1: i64toi64set_shared.TKey key, 2: i64toi64set_shared.TItem item);
	i32 getSize(1: i64toi64set_shared.TKey key);
	map<i64toi64set_shared.TKey, i32> getSizeMulti(1: list<i64toi64set_shared.TKey> keys);
}
