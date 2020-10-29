/*=========================================================================
 *
 *  Copyright UMC Utrecht and contributors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef elxNearestNeighborInterpolator_h
#define elxNearestNeighborInterpolator_h

#include "elxIncludes.h" // include first to avoid MSVS warning
#include "itkNearestNeighborInterpolateImageFunction.h"

namespace elastix
{

/**
 * \class NearestNeighborInterpolator
 * \brief An interpolator based on the itkNearestNeighborInterpolateImageFunction.
 *
 * This interpolator interpolates images using nearest neighbour interpolation.
 * The image derivatives are computed using a central difference scheme.
 *
 * The parameters used in this class are:
 * \parameter Interpolator: Select this interpolator as follows:\n
 *    <tt>(Interpolator "NearestNeighborInterpolator")</tt>
 *
 * \ingroup Interpolators
 */

template <class TElastix>
class NearestNeighborInterpolator
  : public itk::NearestNeighborInterpolateImageFunction<typename InterpolatorBase<TElastix>::InputImageType,
                                                        typename InterpolatorBase<TElastix>::CoordRepType>
  , public InterpolatorBase<TElastix>
{
public:
  /** Standard ITK-stuff. */
  typedef NearestNeighborInterpolator Self;
  typedef itk::NearestNeighborInterpolateImageFunction<typename InterpolatorBase<TElastix>::InputImageType,
                                                       typename InterpolatorBase<TElastix>::CoordRepType>
                                        Superclass1;
  typedef InterpolatorBase<TElastix>    Superclass2;
  typedef itk::SmartPointer<Self>       Pointer;
  typedef itk::SmartPointer<const Self> ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(NearestNeighborInterpolator, itk::NearestNeighborInterpolateImageFunction);

  /** Name of this class.
   * Use this name in the parameter file to select this specific interpolator. \n
   * example: <tt>(Interpolator "NearestNeighborInterpolator")</tt>\n
   */
  elxClassNameMacro("NearestNeighborInterpolator");

  /** Get the ImageDimension. */
  itkStaticConstMacro(ImageDimension, unsigned int, Superclass1::ImageDimension);

  /** Typedefs inherited from the superclass. */
  typedef typename Superclass1::OutputType          OutputType;
  typedef typename Superclass1::InputImageType      InputImageType;
  typedef typename Superclass1::IndexType           IndexType;
  typedef typename Superclass1::ContinuousIndexType ContinuousIndexType;
  typedef typename Superclass1::PointType           PointType;

  /** Typedefs inherited from Elastix. */
  typedef typename Superclass2::ElastixType          ElastixType;
  typedef typename Superclass2::ElastixPointer       ElastixPointer;
  typedef typename Superclass2::ConfigurationType    ConfigurationType;
  typedef typename Superclass2::ConfigurationPointer ConfigurationPointer;
  typedef typename Superclass2::RegistrationType     RegistrationType;
  typedef typename Superclass2::RegistrationPointer  RegistrationPointer;
  typedef typename Superclass2::ITKBaseType          ITKBaseType;

protected:
  /** The constructor. */
  NearestNeighborInterpolator() {}
  /** The destructor. */
  ~NearestNeighborInterpolator() override {}

private:
  /** The private constructor. */
  NearestNeighborInterpolator(const Self &) = delete;
  /** The private copy constructor. */
  void
  operator=(const Self &) = delete;
};

} // end namespace elastix

#ifndef ITK_MANUAL_INSTANTIATION
#  include "elxNearestNeighborInterpolator.hxx"
#endif

#endif // end #ifndef elxNearestNeighborInterpolator_h
