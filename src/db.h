/*
 * db.h
 *     Declared a set of functions responsible for interfacing
 * with RocksDB.
 *
 * Copyright (c) 2024-present, Qihoo, Inc.  All rights reserved.
 *
 * src/db.cc
 *
 */

#pragma once

#include <filesystem>
#include <string>

#include "pstd/log.h"
#include "pstd/noncopyable.h"
#include "storage/storage.h"

namespace pikiwidb {

class DB {
 public:
  DB(int db_index, const std::string& db_path);
  ~DB();

  rocksdb::Status Open();

  std::unique_ptr<storage::Storage>& GetStorage() { return storage_; }

  void Lock() { storage_mutex_.lock(); }

  void UnLock() { storage_mutex_.unlock(); }

  void LockShared() { storage_mutex_.lock_shared(); }

  void UnLockShared() { storage_mutex_.unlock_shared(); }

  void CreateCheckpoint(const std::string& path, bool sync);

  void LoadDBFromCheckpoint(const std::string& path, bool sync = true);

  int GetDbIndex() { return db_index_; }

 private:
  const int db_index_ = 0;
  const std::string db_path_;
  /**
   * If you want to change the pointer that points to storage,
   * you must first acquire a mutex lock.
   * If you only want to access the pointer,
   * you just need to obtain a shared lock.
   */
  std::shared_mutex storage_mutex_;
  std::unique_ptr<storage::Storage> storage_;
  bool opened_ = false;
};

}  // namespace pikiwidb
