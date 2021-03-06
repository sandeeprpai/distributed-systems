/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "places.h"

bool_t
xdr_name (XDR *xdrs, name *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, MAXLEN))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_code (XDR *xdrs, code *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, CODELEN))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_final_result_u (XDR *xdrs, final_result_u *objp)
{
	register int32_t *buf;

	 if (!xdr_final_result (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_location (XDR *xdrs, location *objp)
{
	register int32_t *buf;

	 if (!xdr_coordinates (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_airport_list (XDR *xdrs, airport_list *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)objp, sizeof (struct airport_info), (xdrproc_t) xdr_airport_info))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_airport_info (XDR *xdrs, airport_info *objp)
{
	register int32_t *buf;

	 if (!xdr_code (xdrs, &objp->airport_code))
		 return FALSE;
	 if (!xdr_name (xdrs, &objp->city))
		 return FALSE;
	 if (!xdr_code (xdrs, &objp->state))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->distance))
		 return FALSE;
	 if (!xdr_airport_list (xdrs, &objp->next))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_coordinates (XDR *xdrs, coordinates *objp)
{
	register int32_t *buf;

	 if (!xdr_double (xdrs, &objp->latitude))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->longitude))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_user_input (XDR *xdrs, user_input *objp)
{
	register int32_t *buf;

	 if (!xdr_name (xdrs, &objp->city))
		 return FALSE;
	 if (!xdr_code (xdrs, &objp->state))
		 return FALSE;
	 if (!xdr_location (xdrs, &objp->loc))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_final_result (XDR *xdrs, final_result *objp)
{
	register int32_t *buf;

	 if (!xdr_user_input (xdrs, &objp->input_res))
		 return FALSE;
	 if (!xdr_airport_list (xdrs, &objp->list))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_list_airport (XDR *xdrs, list_airport *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->errno))
		 return FALSE;
	switch (objp->errno) {
	case 0:
		 if (!xdr_final_result_u (xdrs, &objp->list_airport_u.result))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}
