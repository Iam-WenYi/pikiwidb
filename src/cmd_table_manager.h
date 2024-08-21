/*
 * cmd_table_manager.h
 *     Defined a command table, because PikiwiDB needs to manage 
 * commands in an integrated way.
 * 
 * Copyright (c) 2023-present, Qihoo, Inc.  All rights reserved.
 * 
 * src/cmd_table_manager.h
 * 
 */

#pragma once

#include <memory>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>
#include <unordered_map>

#include "base_cmd.h"

namespace pikiwidb {

using CmdTable = std::unordered_map<std::string, std::unique_ptr<BaseCmd>>;

class CmdTableManager {
 public:
  CmdTableManager();
  ~CmdTableManager() = default;

 public:
  void InitCmdTable();
  std::pair<BaseCmd*, CmdRes::CmdRet> GetCommand(const std::string& cmdName, PClient* client);
  //  uint32_t DistributeKey(const std::string& key, uint32_t slot_num);
  bool CmdExist(const std::string& cmd) const;
  uint32_t GetCmdId();

 private:
  std::unique_ptr<CmdTable> cmds_;

  uint32_t cmdId_ = 0;

  mutable std::shared_mutex mutex_;
};

}  // namespace pikiwidb
