/*
 * proto_parser.h
 *     Responsible for declaring functions and instructions for 
 * handling the Redis client protocol.
 * 
 * Copyright (c) 2023-present, Qihoo, Inc.  All rights reserved.
 * 
 * src/proto_parser.cc
 * 
 */

#pragma once

#include <vector>

#include "common.h"

namespace pikiwidb {

class PProtoParser {
 public:
  PProtoParser() = delete;
  explicit PProtoParser(std::vector<std::string>& params) : params_(params) {}
  void Reset();
  PParseResult ParseRequest(const char*& ptr, const char* end);

  const std::vector<std::string>& GetParams() const { return params_; }
  void SetParams(std::vector<std::string> p) { params_ = std::move(p); }

  bool IsInitialState() const { return multi_ == -1; }

 private:
  PParseResult parseMulti(const char*& ptr, const char* end, int& result);
  PParseResult parseStrlist(const char*& ptr, const char* end, std::vector<std::string>& results);
  PParseResult parseStr(const char*& ptr, const char* end, std::string& result);
  PParseResult parseStrval(const char*& ptr, const char* end, std::string& result);
  PParseResult parseStrlen(const char*& ptr, const char* end, int& result);

  int multi_ = -1;
  int paramLen_ = -1;

  size_t numOfParam_ = 0;  // for optimize
  std::vector<std::string>& params_;
};

}  // namespace pikiwidb
