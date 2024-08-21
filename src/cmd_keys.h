/*
 * cmd_keys.h
 *     This file defines some functions and commands related
 * to key operations.
 *
 * Copyright (c) 2023-present, Qihoo, Inc.  All rights reserved.
 *
 * src/cmd_keys.h
 *
 */

#pragma once

#include "base_cmd.h"

namespace pikiwidb {

class DelCmd : public BaseCmd {
 public:
  DelCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class ExistsCmd : public BaseCmd {
 public:
  ExistsCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class TypeCmd : public BaseCmd {
 public:
  TypeCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class ExpireCmd : public BaseCmd {
 public:
  ExpireCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class TtlCmd : public BaseCmd {
 public:
  TtlCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class PExpireCmd : public BaseCmd {
 public:
  PExpireCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class ExpireatCmd : public BaseCmd {
 public:
  ExpireatCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class PExpireatCmd : public BaseCmd {
 public:
  PExpireatCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class PersistCmd : public BaseCmd {
 public:
  PersistCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class KeysCmd : public BaseCmd {
 public:
  KeysCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class PttlCmd : public BaseCmd {
 public:
  PttlCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class RenameCmd : public BaseCmd {
 public:
  RenameCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

class RenameNXCmd : public BaseCmd {
 public:
  RenameNXCmd(const std::string& name, int16_t arity);

 protected:
  bool DoInitial(PClient* client) override;

 private:
  void DoCmd(PClient* client) override;
};

}  // namespace pikiwidb
