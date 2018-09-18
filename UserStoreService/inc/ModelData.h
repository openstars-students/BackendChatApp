/* 
 * File:   Model.h
 * Author: trungthanh
 *
 * Created on February 01, 2018, 6:16 PM
 */

#ifndef _MODELDATA_H
#define _MODELDATA_H

#include <vector>
#include "userstore_types.h"
#include <iostream>
namespace model {

    
    class ModelData {
    public:
        
        OpenStars::Platform::UserStore::TUserInfo data;
        
        ModelData(void) {            
        }

        void assignTo(OpenStars::Platform::UserStore::TUserInfo& value) const {
            value = data;
        }

        void assignFrom(const OpenStars::Platform::UserStore::TUserInfo& value) {
            this->data = value;
        }
        OpenStars::Platform::UserStore::TErrorCode::type deleteLogicData(){
            OpenStars::Platform::UserStore::TErrorCode error;
            this->data.status=0;
            //OpenStars::Platform::MessageStore::TErrorCode err;
            return error.EGood;
        }
        bool hasUser(std::string uname){
            if(this->data.username==uname)
                return true;
            else return false;
        }
        
        bool hasPublicKey(std::string uname){
            if(this->data.publickey==uname)
                return true;
            else return false;
        }
        
        OpenStars::Platform::UserStore::TErrorCode::type addConversation(const int64_t item) {
            OpenStars::Platform::UserStore::TErrorCode error;
            std::vector<int64_t>::iterator pos = std::lower_bound(data.listconversation.begin(), data.listconversation.end(), item);
            //std::cout<<"\tgia tri"<<*pos<<std::endl;
            if ((pos == data.listconversation.end()) || (*pos != item)) {
                data.listconversation.insert(pos, item);
                return error.EGood;
                //std::cout<<"vao den day!"<<std::endl;
            }
            if(*pos==item) return error.EDataExisted;
            return error.EUnknown;
        }
        OpenStars::Platform::UserStore::TErrorCode::type deleteConversation(const int64_t item) {
            OpenStars::Platform::UserStore::TErrorCode error;
            std::vector<int64_t>::iterator pos = std::lower_bound(data.listconversation.begin(), data.listconversation.end(), item);
            std::cout<<"\tgia tri"<<*pos<<std::endl;
            if ((pos != data.listconversation.end()) && (*pos == item)) {
                data.listconversation.erase(pos);
                std::cout<<"vao den day! "<<std::endl;
                return error.EGood;            
            }
            if(*pos!=item) return error.ENotFound;
            return error.EUnknown;
        }


    };

}

#endif 
