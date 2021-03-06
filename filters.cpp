#include "filters.h"

cv::Mat create1DGaussianKernel(float sigma, int radius)
{
  if (radius <= 0) radius = static_cast<int>(std::ceil(3.5f * sigma));

  const int length = 2*radius + 1;
  cv::Mat kernel(length, 1, CV_32F);

  const float factor = -0.5f / (sigma*sigma);
  float sum = 0.f;

  for (int i = 0; i < length; ++i)
  {
    const auto x = static_cast<float>(i - radius);
    const float kernel_element = std::exp(x * x * factor);
    kernel.at<float>(i) = kernel_element;
    sum += kernel_element;
  }

  kernel /= sum;
  return kernel;
}

cv::Mat create1DDerivatedGaussianKernel(float sigma, int radius)
{
  if (radius <= 0) radius = static_cast<int>(std::ceil(3.5f * sigma));

  // Todo 1: Use create1DGaussianKernel to finish this function.
  cv::Mat kernel = create1DGaussianKernel(sigma, radius); 
  
  const int length = 2 * radius + 1; 
  for (int i = 0; i < length; ++i) 
  {
    const float x = static_cast<float>(i - radius); 
    kernel.at<float>(i) *= -x / (sigma * sigma); 
  }

  return kernel;
}
