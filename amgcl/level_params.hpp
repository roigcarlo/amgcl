#ifndef AMGCL_LEVEL_PARAMS_HPP
#define AMGCL_LEVEL_PARAMS_HPP

/*
The MIT License

Copyright (c) 2012 Denis Demidov <ddemidov@ksu.ru>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/**
 * \file   level_params.hpp
 * \author Denis Demidov <ddemidov@ksu.ru>
 * \brief  Common parameters for level construction/solution.
 */

namespace amgcl {

namespace level {

/// Common parameters for level construction/solution.
struct params {
    /// Number of pre-relaxations.
    unsigned npre;

    /// Number of post-relaxations.
    unsigned npost;

    /// Number of cycles (1 for V-cycle, 2 for W-cycle, etc.).
    unsigned ncycle;

    /// How often to invoke k-cycle instead of just v-cycle.
    /**
     * See \ref Notay_2008 "Notay (2008)". K-cycle employs a Krylov method
     * (here CG) on each level of the grid hierarchy and uses this grid
     * hierarchy for the preconditioning of this Krylov method. The approach is
     * further extended by allowing such inner iterations only at levels of
     * given multiplicity, whereas normal V-cycle formulation is used at all
     * other levels.
     */
    // TODO: Try flexible (generalized) CG method here.
    unsigned kcycle;

    /// Under-relaxation factor.
    float relax_factor;

    /// Maximum number of iterations in standalone solver.
    unsigned maxiter;

    /// The required precision for standalone solver.
    double   tol;

    params()
        : npre(1), npost(1), ncycle(1), kcycle(0), relax_factor(0.72f),
          maxiter(100), tol(1e-8)
    { }
};

} // namespace level
} // namespace amgcl

#endif
