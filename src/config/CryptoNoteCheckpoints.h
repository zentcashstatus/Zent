// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2019, The Zent Cash project
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {
struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {   
{       0, "7c02559783a46e9401a1539cc90571f29b3f1cf231f5fea6b8fbbe09a16a4f29"}, 
{       2, "b551967e99b7916e566ea92ca249281b0dc6304aa0be3844625698f46282a323"}, 
{    4000, "046c85fbb925a5c100b6bf762cadadd5cc806757f861bd7ecd2e6bdcb69c056c"}, 
{    8000, "be737f63929fe05533d32a1efbe873a9a86ba6e67a7bf0a622383e16ce3daafe"}, 
}; 
} 
