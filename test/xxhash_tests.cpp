/*
    Land of the Rair
    Copyright (C) 2019  Michael de Lang

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

#include <catch2/catch.hpp>
#include <spdlog/spdlog.h>
#include "test_helpers/startup_helper.h"
#include "game_logic/fov.h"
#include <ecs/components.h>

using namespace std;
using namespace lotr;

TEST_CASE("ensure xxhash has no collisions for map locations") {
    lotr_flat_map <uint64_t, bool> hashes;
    for(int x = -1000; x < 1000; x++) {
        for(int y = -1000; y < 1000; y++) {
            auto t = make_tuple(x, y);
            auto hash = XXH3_64bits(&t, sizeof(uint64_t) * 2);

            if(hashes.find(hash) != end(hashes)) {
                spdlog::error("hash already found! {}", hash);
            } else {
                hashes[hash] = true;
            }
        }
    }
}
