#ifndef Asset_h
#define Asset_h

#include "Enumeration.h"
#include <string>

namespace Quark {
    class Asset {
        friend class AssetManager;
    public:
        Asset();
        virtual ~Asset();
        
    private:
        void AddReference();
        void RemoveReference();
        
    protected:
        Enumeration::AssetType mType;
        unsigned int mRefCount;
        std::string mName;
    };
}

#endif /* Asset_h */