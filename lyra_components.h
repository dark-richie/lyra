/*
 * Copyright 2021 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LYRA_CODEC_LYRA_COMPONENTS_H_
#define LYRA_CODEC_LYRA_COMPONENTS_H_

#include <memory>

#include "feature_estimator_interface.h"
#include "feature_extractor_interface.h"
#include "generative_model_interface.h"
#include "include/ghc/filesystem.hpp"
#include "packet_interface.h"
#include "vector_quantizer_interface.h"

namespace chromemedia {
namespace codec {

std::unique_ptr<VectorQuantizerInterface> CreateQuantizer(
    int num_output_features, const ghc::filesystem::path& model_path);

std::unique_ptr<GenerativeModelInterface> CreateGenerativeModel(
    int num_samples_per_hop, int num_output_features,
    const ghc::filesystem::path& model_path);

std::unique_ptr<FeatureExtractorInterface> CreateFeatureExtractor(
    int sample_rate_hz, int num_features, int num_samples_per_hop,
    int num_samples_per_window, const ghc::filesystem::path& model_path);

std::unique_ptr<PacketInterface> CreatePacket(int num_header_bits,
                                              int num_quantized_bits);

std::unique_ptr<FeatureEstimatorInterface> CreateFeatureEstimator(
    int num_features);

}  // namespace codec
}  // namespace chromemedia

#endif  // LYRA_CODEC_LYRA_COMPONENTS_H_
