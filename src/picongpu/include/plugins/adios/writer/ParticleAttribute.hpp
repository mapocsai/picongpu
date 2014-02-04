/**
 * Copyright 2014 Axel Huebl, Felix Schmitt, Heiko Burau, Rene Widera
 *
 * This file is part of PIConGPU. 
 * 
 * PIConGPU is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version. 
 * 
 * PIConGPU is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public License 
 * along with PIConGPU.  
 * If not, see <http://www.gnu.org/licenses/>. 
 */

#pragma once

#include "types.h"
#include "simulation_types.hpp"
#include "plugins/adios/ADIOSWriter.def"
#include "traits/PICToAdios.hpp"
#include "traits/GetComponentsType.hpp"
#include "traits/GetNComponents.hpp"


namespace picongpu
{

namespace adios
{
using namespace PMacc;

namespace bmpl = boost::mpl;

/** write attribute of a particle to adios file
 * 
 * @tparam T_Identifier identifier of a particle attribute
 */
template< typename T_Identifier>
struct ParticleAttribute
{

    /** write attribute to adios file
     * 
     * @param params wrapped params with domainwriter, ...
     * @param frame frame with all particles 
     * @param prefix a name prefix for adios attribute (is combined to: prefix_nameOfAttribute)
     * @param simOffset offset from window origin of thedomain
     * @param localSize local domain size 
     */
    template<typename FrameType>
    HINLINE void operator()(
                            const RefWrapper<ThreadParams*> params,
                            const RefWrapper<FrameType> frame,
                            const std::string subGroup,
                            const DomainInformation domInfo,
                            const size_t elements)
    {

        /*typedef T_Identifier Identifier;
        typedef typename Identifier::type ValueType;
        const uint32_t components = GetNComponents<ValueType>::value;
        typedef typename GetComponentsType<ValueType>::type ComponentType;

        typedef typename PICtoAdios<ComponentType>::type AdiosType;

        log<picLog::INPUT_OUTPUT > ("ADIOS:  (begin) write species attribute: %1%") % Identifier::getName();

        AdiosType adiosType;
        const std::string name_lookup[] = {"x", "y", "z"};

        std::vector<double> unit = Unit<T_Identifier>::get();

        Dimensions splashDomainOffset(0, 0, 0);
        Dimensions splashGlobalDomainOffset(0, 0, 0);

        Dimensions splashDomainSize(1, 1, 1);
        Dimensions splashGlobalDomainSize(1, 1, 1);

        for (uint32_t d = 0; d < simDim; ++d)
        {
            splashDomainOffset[d] = domInfo.domainOffset[d] + globalSlideOffset[d];
            splashGlobalDomainOffset[d] = domInfo.globalDomainOffset[d] + globalSlideOffset[d];
            splashGlobalDomainSize[d] = domInfo.globalDomainSize[d];
            splashDomainSize[d] = domInfo.domainSize[d];
        }

        for (uint32_t d = 0; d < components; d++)
        {
            std::stringstream datasetName;
            datasetName << subGroup << "/" << T_Identifier::getName();
            if (components > 1)
                datasetName << "/" << name_lookup[d];

            ValueType* dataPtr = frame.get().getIdentifier(Identifier()).getPointer();

            params.get()->dataCollector->writeDomain(params.get()->currentStep, 
                                                     adiosType, 
                                                     1u, 
                                                     Dimensions(elements*components, 1, 1),
                                                     Dimensions(components, 1, 1),
                                                     Dimensions(elements, 1, 1),
                                                     Dimensions(d, 0, 0),
                                                     datasetName.str().c_str(), 
                                                     splashDomainOffset, 
                                                     splashDomainSize, 
                                                     splashGlobalDomainOffset, 
                                                     splashGlobalDomainSize, 
                                                     DomainCollector::PolyType,
                                                     dataPtr);

            ColTypeDouble ctDouble;
            if (unit.size() >= (d + 1))
                params.get()->dataCollector->writeAttribute(params.get()->currentStep,
                                                            ctDouble, datasetName.str().c_str(),
                                                            "sim_unit", &(unit.at(d)));


        }
        log<picLog::INPUT_OUTPUT > ("ADIOS:  ( end ) write species attribute: %1%") %
            Identifier::getName();*/
    }

};

} //namspace adios

} //namespace picongpu

