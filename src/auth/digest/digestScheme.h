/*
 * $Id$
 *
 *
 * SQUID Web Proxy Cache          http://www.squid-cache.org/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from
 *  the Internet community; see the CONTRIBUTORS file for full
 *  details.   Many organizations have provided support for Squid's
 *  development; see the SPONSORS file for full details.  Squid is
 *  Copyrighted (C) 2001 by the Regents of the University of
 *  California; see the COPYRIGHT file for full details.  Squid
 *  incorporates software developed and/or copyrighted by other
 *  sources; see the CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */

#ifndef SQUID_DIGESTSCHEME_H
#define SQUID_DIGESTSCHEME_H

#include "auth/Scheme.h"
#include "auth/digest/auth_digest.h"

/// \ingroup AuthSchemeAPI
/// \ingroup AuthAPI
class digestScheme : public AuthScheme
{

public:
    static AuthScheme::Pointer GetInstance();
    digestScheme() {};
    virtual ~digestScheme() {}

    /* per scheme */
    virtual char const *type () const;
    virtual void done();
    virtual AuthConfig *createConfig();

    /* Not implemented */
    digestScheme (digestScheme const &);
    digestScheme &operator=(digestScheme const &);

private:
    static AuthScheme::Pointer _instance;

    /**
     * Remove all cached user credentials from circulation.
     * Intended for use during shutdown procedure.
     * After calling this all newly received credentials must be re-authenticated.
     */
    static void PurgeCredentialsCache(void);
};

#endif /* SQUID_DIGESTSCHEME_H */
