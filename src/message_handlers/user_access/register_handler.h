/*
    Land of the Rair
    Copyright (C) 2019 Michael de Lang

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <App.h>
#include <rapidjson/document.h>
#include <database/database_pool.h>
#include <per_socket_data.h>
#include <readerwriterqueue.h>
#include <game_queue_messages/messages.h>

using namespace std;

namespace lotr {
    void handle_register(uWS::WebSocket<false, true> *ws, uWS::OpCode op_code, rapidjson::Document const &d, shared_ptr<database_pool> pool,
            per_socket_data *user_data, moodycamel::ReaderWriterQueue<unique_ptr<queue_message>> &q);
}
