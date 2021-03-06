/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "proton/listener.hpp"

#include <proton/listener.h>

#include "contexts.hpp"

namespace proton {

listener::listener(): listener_(0) {}
listener::listener(pn_listener_t* l): listener_(l) {}
// Out-of-line big-3 with trivial implementations, in case we need them in future. 
listener::listener(const listener& l) : listener_(l.listener_) {}
listener::~listener() {}
listener& listener::operator=(const listener& l) { listener_ = l.listener_; return *this; }

// FIXME aconway 2017-10-06: should be a no-op if already closed
void listener::stop() { if (listener_) pn_listener_close(listener_); }

}
