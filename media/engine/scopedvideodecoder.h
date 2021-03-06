/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef MEDIA_ENGINE_SCOPEDVIDEODECODER_H_
#define MEDIA_ENGINE_SCOPEDVIDEODECODER_H_

#include <memory>

#include "api/video_codecs/video_decoder.h"
#include "media/base/codec.h"
#include "media/engine/webrtcvideodecoderfactory.h"
#include "rtc_base/deprecation.h"

namespace cricket {

std::unique_ptr<webrtc::VideoDecoder> DEPRECATED_CreateScopedVideoDecoder(
    cricket::WebRtcVideoDecoderFactory* factory,
    const VideoCodec& codec,
    VideoDecoderParams params);

// Helper function that creates a webrtc::VideoDecoder held by an
// std::unique_ptr instead of having to be deleted through
// WebRtcVideoDecoderFactory::DestroyVideoDecoder. The factory passed in must
// outlive the returned encoder.
// TODO(andersc): This helper function will be deleted once
// cricket::WebRtcVideoDecoderFactory is deprecated, see
// https://bugs.chromium.org/p/webrtc/issues/detail?id=7925 for more info.
RTC_DEPRECATED inline std::unique_ptr<webrtc::VideoDecoder>
CreateScopedVideoDecoder(cricket::WebRtcVideoDecoderFactory* factory,
                         const VideoCodec& codec,
                         VideoDecoderParams params) {
  return DEPRECATED_CreateScopedVideoDecoder(factory, codec, params);
}

}  // namespace cricket

#endif  // MEDIA_ENGINE_SCOPEDVIDEODECODER_H_
