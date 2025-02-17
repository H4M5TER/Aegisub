// Copyright (c) 2019, Charlie Jiang <cqjjjzr@126.com>
//
// Permission to use, copy, modify, and distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

/// @file resources_fs.h
/// @brief Interface for resource(bitmap, config, ...) loading FROM FILESYSTEM.
/// @ingroup libaegisub

#pragma once

#include <string>
#include <string_view>

#include <boost/optional.hpp>

class wxBitmap;
class wxIcon;

namespace agi::resources::fs
{
extern const std::string imageResourceExt;
extern const std::string iconResourceExt;
extern const std::string configResourceExt;
extern const std::string resourcePathPrefix;

/// Load image resource using name.
/// @param dir The image direction
boost::optional<wxBitmap> LoadImageRes(std::string_view name, int dir = 0);
/// Load icon resource using name.
boost::optional<wxIcon> LoadIconRes(std::string_view name);
/// Load config string resource using name.
boost::optional<std::string> LoadConfig(std::string_view name);
}
