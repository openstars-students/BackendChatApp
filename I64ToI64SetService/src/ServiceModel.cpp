/* 
 * File:   ZServiceModel.cpp
 * Author: trungthanh
 * 
 * Created on February 23, 2012, 6:13 PM
 */

#include "ServiceModel.h"

using namespace std;

ServiceModel::ServiceModel(Poco::SharedPtr<PersistentStorageType> aStorage) : m_storage(aStorage) {
}

ServiceModel::~ServiceModel(void) {
}

void ServiceModel::getValue(OpenStars::Core::I64ToI64Set::Data::TValue& _return, const OpenStars::Core::I64ToI64Set::Data::TKey key) {

    class get_value_visitor : public PersistentStorageType::data_visitor {
    public:

        get_value_visitor(OpenStars::Core::I64ToI64Set::Data::TValue& _value) : value(_value) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->value);
            return false;
        }

        OpenStars::Core::I64ToI64Set::Data::TValue& value;
    };

    _return.items.clear();
    if (this->m_storage) {
        get_value_visitor visitor(_return);
        this->m_storage->visit(key, &visitor);        
    }
}

void ServiceModel::getValue_random(OpenStars::Core::I64ToI64Set::Data::TValue& _return, const OpenStars::Core::I64ToI64Set::Data::TKey key, const int32_t size) {

    class get_value_random_visitor : public PersistentStorageType::data_visitor {
    public:

        get_value_random_visitor(OpenStars::Core::I64ToI64Set::Data::TValue& _value, const int32_t _size) : value(_value), size(_size) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.getItems_random(this->value, size);
            return false;
        }

        OpenStars::Core::I64ToI64Set::Data::TValue& value;
        const int32_t size;
    };

    _return.items.clear();
    if (this->m_storage) {
        get_value_random_visitor visitor(_return, size);
        this->m_storage->visit(key, &visitor);
    }
}

void ServiceModel::getValue_slice(OpenStars::Core::I64ToI64Set::Data::TValue& _return, const OpenStars::Core::I64ToI64Set::Data::TKey key, const int32_t idxFrom, const int32_t size) {

    class get_value_slice_visitor : public PersistentStorageType::data_visitor {
    public:

        get_value_slice_visitor(OpenStars::Core::I64ToI64Set::Data::TValue& _value, const int32_t _idxFrom, const int32_t _size) : value(_value), idxFrom(_idxFrom), size(_size) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.getItems_slice(this->value, idxFrom, size);
            return false;
        }

        OpenStars::Core::I64ToI64Set::Data::TValue& value;
        const int32_t idxFrom;
        const int32_t size;
    };

    _return.items.clear();
    if (this->m_storage) {
        get_value_slice_visitor visitor(_return, idxFrom, size);
        this->m_storage->visit(key, &visitor);
    }
}

void ServiceModel::getValueMulti(map<OpenStars::Core::I64ToI64Set::Data::TKey, OpenStars::Core::I64ToI64Set::Data::TValue>& _return, const vector<OpenStars::Core::I64ToI64Set::Data::TKey>& keys) {

    class get_value_visitor : public PersistentStorageType::data_visitor {
    public:

        get_value_visitor(OpenStars::Core::I64ToI64Set::Data::TValue& _value) : value(_value) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->value);
            return false;
        }

        OpenStars::Core::I64ToI64Set::Data::TValue& value;
    };

    _return.clear();
    if (this->m_storage) {
        OpenStars::Core::I64ToI64Set::Data::TValue value;
        get_value_visitor visitor(value);
        for (vector<OpenStars::Core::I64ToI64Set::Data::TKey>::const_iterator pos = keys.begin(); pos != keys.end(); pos++) {
            this->m_storage->visit(*pos, &visitor);
            _return.insert(pair<OpenStars::Core::I64ToI64Set::Data::TKey, OpenStars::Core::I64ToI64Set::Data::TValue>(*pos, visitor.value));
        }
    }
}

bool ServiceModel::hasItem(const OpenStars::Core::I64ToI64Set::Data::TKey key, const OpenStars::Core::I64ToI64Set::Data::TItem item) {

    class has_item_visitor : public PersistentStorageType::data_visitor {
    public:

        has_item_visitor(const OpenStars::Core::I64ToI64Set::Data::TItem _item) : item(_item), result(false) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            result = value.hasItem(item);
            return false;
        }

        bool result;
        const OpenStars::Core::I64ToI64Set::Data::TItem item;
    };

    if (this->m_storage) {
        has_item_visitor visitor(item);
        this->m_storage->visit(key, &visitor);
        return visitor.result;
    }
    return false;
}

int32_t ServiceModel::getSize(const OpenStars::Core::I64ToI64Set::Data::TKey key) {

    class get_size_visitor : public PersistentStorageType::data_visitor {
    public:

        get_size_visitor(void) : size(-1) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            size = value.getSize();
            return false;
        }

        int32_t size;
    };

    if (this->m_storage) {
        get_size_visitor visitor;
        this->m_storage->visit(key, &visitor);
        return visitor.size;
    }
    return -1;
}

void ServiceModel::getSizeMulti(std::map<OpenStars::Core::I64ToI64Set::Data::TKey, int32_t>& _return, const std::vector<OpenStars::Core::I64ToI64Set::Data::TKey>& keys) {

    class get_size_visitor : public PersistentStorageType::data_visitor {
    public:

        get_size_visitor(void) : size(-1) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            size = value.getSize();
            return false;
        }

        int32_t size;
    };

    _return.clear();
    if (this->m_storage) {
        get_size_visitor visitor;
        for (vector<OpenStars::Core::I64ToI64Set::Data::TKey>::const_iterator pos = keys.begin(); pos != keys.end(); pos++) {
            this->m_storage->visit(*pos, &visitor);
            _return.insert(pair<OpenStars::Core::I64ToI64Set::Data::TKey, int32_t>(*pos, visitor.size));
        }
    }
}

bool ServiceModel::setItems(const OpenStars::Core::I64ToI64Set::Data::TKey key, const vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items) {

    class set_items_visitor : public PersistentStorageType::data_visitor {
    public:

        set_items_visitor(const vector<OpenStars::Core::I64ToI64Set::Data::TItem>& _items) : items(_items), result(false) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            result = value.setItems(items);
            return true;
        }

        bool result;
        const vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items;
    };

    if (this->m_storage) {
        set_items_visitor visitor(items);
        this->m_storage->visit(key, &visitor);
        return visitor.result;
    }
    return false;
}

bool ServiceModel::clearItems(const OpenStars::Core::I64ToI64Set::Data::TKey key) {

    class clear_items_visitor : public PersistentStorageType::data_visitor {
    public:

        clear_items_visitor(void) : result(false) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            result = value.clearItems();
            return true;
        }

        bool result;
    };

    if (this->m_storage) {
        clear_items_visitor visitor;
        this->m_storage->visit(key, &visitor);
        return visitor.result;
    }
    return false;
}

bool ServiceModel::addItem(const OpenStars::Core::I64ToI64Set::Data::TKey key, const OpenStars::Core::I64ToI64Set::Data::TItem item) {

    class add_item_visitor : public PersistentStorageType::data_visitor {
    public:

        add_item_visitor(const OpenStars::Core::I64ToI64Set::Data::TItem _item) : item(_item), result(false) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            result = value.addItem(item);
            return true;
        }

        bool result;
        const OpenStars::Core::I64ToI64Set::Data::TItem item;
    };

    if (this->m_storage) {
        add_item_visitor visitor(item);
        this->m_storage->visit(key, &visitor);
        return visitor.result;
    }
    return false;
}

bool ServiceModel::addItems(const OpenStars::Core::I64ToI64Set::Data::TKey key, const vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items) {

    class add_items_visitor : public PersistentStorageType::data_visitor {
    public:

        add_items_visitor(const vector<OpenStars::Core::I64ToI64Set::Data::TItem>& _items) : items(_items), result(false) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            result = value.addItems(items);
            return true;
        }

        bool result;
        const vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items;
    };

    if (this->m_storage) {
        add_items_visitor visitor(items);
        this->m_storage->visit(key, &visitor);
        return visitor.result;
    }
    return false;
}

bool ServiceModel::removeItem(const OpenStars::Core::I64ToI64Set::Data::TKey key, const OpenStars::Core::I64ToI64Set::Data::TItem item) {

    class remove_item_visitor : public PersistentStorageType::data_visitor {
    public:

        remove_item_visitor(const OpenStars::Core::I64ToI64Set::Data::TItem _item) : item(_item), result(false) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            result = value.removeItem(item);
            return true;
        }

        bool result;
        const OpenStars::Core::I64ToI64Set::Data::TItem item;
    };

    if (this->m_storage) {
        remove_item_visitor visitor(item);
        this->m_storage->visit(key, &visitor);
        return visitor.result;
    }
    return false;
}

bool ServiceModel::removeItems(const OpenStars::Core::I64ToI64Set::Data::TKey key, const vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items) {

    class remove_items_visitor : public PersistentStorageType::data_visitor {
    public:

        remove_items_visitor(const vector<OpenStars::Core::I64ToI64Set::Data::TItem>& _items) : items(_items), result(false) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            result = value.removeItems(items);
            return true;
        }

        bool result;
        const vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items;
    };

    if (this->m_storage) {
        remove_items_visitor visitor(items);
        this->m_storage->visit(key, &visitor);
        return visitor.result;
    }
    return false;
}
