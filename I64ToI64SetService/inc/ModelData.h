/* 
 * File:   Model.h
 * Author: trungthanh
 *
 * Created on February 01, 2018, 6:16 PM
 */

#ifndef I64I64SET_MODELDATA_H
#define I64I64SET_MODELDATA_H

#include <vector>
#include "i64toi64set_shared_types.h"

namespace model {

    class ModelData {
    public:
        std::vector<OpenStars::Core::I64ToI64Set::Data::TItem> items;

        ModelData(void) {
            
        }

        void assignTo(OpenStars::Core::I64ToI64Set::Data::TValue& value) const {
            value.items = this->items;
        }

        void assignFrom(const OpenStars::Core::I64ToI64Set::Data::TValue& value) {
            this->items = value.items;
        }

        int32_t getSize(void) const {
            return this->items.size();
        }

        bool hasItem(const OpenStars::Core::I64ToI64Set::Data::TItem item) const {
            std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>::const_iterator pos = std::lower_bound(items.begin(), items.end(), item);
            return ((pos != items.end()) && (*pos == item));
        }

        void getItems_random(OpenStars::Core::I64ToI64Set::Data::TValue& value, const int32_t size) const {
            int nsize = this->items.size();
            if (size >= nsize) {
                value.items = this->items;
                return;
            }

            value.items.clear();

            std::vector<int32_t> indexes;
            for (int i = 0; i < nsize; i++) indexes.push_back(i);

            int32_t idx;
            nsize = size;
            while (nsize > 0) {
                nsize--;
                idx = random() % indexes.size();
                value.items.push_back(this->items[indexes[idx]]);
                indexes.erase(indexes.begin() + idx);
            }
        }

        void getItems_slice(OpenStars::Core::I64ToI64Set::Data::TValue& value, const int32_t idxFrom, const int32_t size) const {
            for (int i = idxFrom, j = 0; (i < this->items.size()) && (j < size); i++, j++)
                value.items.push_back(this->items[i]);
        }

        bool setItems(const std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items) {
            this->items = items;
            return true;
        }

        bool clearItems(void) {
            this->items.clear();
            return true;
        }

        bool addItem(const OpenStars::Core::I64ToI64Set::Data::TItem item) {
            std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>::iterator pos = std::lower_bound(items.begin(), items.end(), item);
            if ((pos == items.end()) || (*pos != item)) {
                items.insert(pos, item);
                return true;
            }
            return false;
        }

        bool addItems(const std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items) {
            for (std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>::const_iterator itemspos = items.begin(); itemspos != items.end(); itemspos++) {
                std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>::iterator pos = std::lower_bound(this->items.begin(), this->items.end(), *itemspos);
                if ((pos == this->items.end()) || (*pos != *itemspos))
                    this->items.insert(pos, *itemspos);
            }
            return true;
        }

        bool removeItem(const OpenStars::Core::I64ToI64Set::Data::TItem item) {
            std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>::iterator pos = std::lower_bound(items.begin(), items.end(), item);
            if ((pos != items.end()) && (*pos == item)) {
                items.erase(pos);
                return true;
            }
            return false;
        }

        bool removeItems(const std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items) {
            for (std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>::const_iterator itemspos = items.begin(); itemspos != items.end(); itemspos++) {
                std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>::iterator pos = std::lower_bound(this->items.begin(), this->items.end(), *itemspos);
                if ((pos != this->items.end()) && (*pos == *itemspos))
                    this->items.erase(pos);
            }
            return true;
        }
    };

    

}

#endif /* ZCACHEVALUE_H */
