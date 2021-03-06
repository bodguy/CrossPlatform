// Copyright (C) 2017 by bodguy
// This code is licensed under Apache 2.0 license (see LICENSE.md for details)

#include "Message.h"

namespace Theodore {
  Message::Message() : mType(), mData(nullptr) {}

  Message::Message(MessageType type) : mType(type), mData(nullptr) {}

  Message::Message(MessageType type, void* data) : mType(type), mData(data) {}

  Message::Message(const Message& rhs) {
    mType = rhs.mType;
    mData = rhs.mData;
  }

  Message& Message::operator=(const Message& rhs) {
    mType = rhs.mType;
    mData = rhs.mData;
    return *this;
  }

  MessageType Message::GetType() const { return mType; }

  void* Message::GetData() const { return mData; }
}  // namespace Theodore
