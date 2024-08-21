/*
 * slow_log.h
 *     Declared a set of features related to the slow log.
 * 
 * Copyright (c) 2023-present, Qihoo, Inc.  All rights reserved.
 * 
 * src/slow_log.h
 * 
 */

#pragma once

#include <deque>
#include <vector>

#include "common.h"

class Logger;

namespace pikiwidb {

struct SlowLogItem {
  unsigned used;
  std::vector<PString> cmds;

  SlowLogItem() : used(0) {}

  SlowLogItem(SlowLogItem&& item) noexcept : used(item.used), cmds(std::move(item.cmds)) {}
};

class PSlowLog {
 public:
  static PSlowLog& Instance();

  PSlowLog(const PSlowLog&) = delete;
  void operator=(const PSlowLog&) = delete;

  void Begin();
  void EndAndStat(const std::vector<PString>& cmds);

  void SetThreshold(unsigned int);
  void SetLogLimit(std::size_t maxCount);

  void ClearLogs() { logs_.clear(); }
  std::size_t GetLogsCount() const { return logs_.size(); }
  const std::deque<SlowLogItem>& GetLogs() const { return logs_; }

 private:
  PSlowLog();
  ~PSlowLog();

  unsigned int threshold_;
  long long beginUs_;
  Logger* logger_;

  std::size_t logMaxCount_;
  std::deque<SlowLogItem> logs_;
};

}  // namespace pikiwidb
