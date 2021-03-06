/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "webtoon.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
webtoon_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		compte inscription_1_arg;
		compte maj_info_1_arg;
		argTri afficher_serie_1_arg;
		argAchaSerie acheter_serie_1_arg;
		argAjouterNote ajouter_note_1_arg;
		argAchaCoin acheter_coin_1_arg;
		compte afficher_coin_1_arg;
		argAchaSerie ajouter_favoris_1_arg;
		compte afficher_favoris_1_arg;
		argAchaSerie supprimer_favoris_1_arg;
		argAjoutComm ajouter_commentaire_1_arg;
		argAjoutComm supprimer_commentaire_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case INIT:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) init_1_svc;
		break;

	case INSCRIPTION:
		_xdr_argument = (xdrproc_t) xdr_compte;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) inscription_1_svc;
		break;

	case MAJ_INFO:
		_xdr_argument = (xdrproc_t) xdr_compte;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) maj_info_1_svc;
		break;

	case AFFICHER_SERIE:
		_xdr_argument = (xdrproc_t) xdr_argTri;
		_xdr_result = (xdrproc_t) xdr_listSerie;
		local = (char *(*)(char *, struct svc_req *)) afficher_serie_1_svc;
		break;

	case ACHETER_SERIE:
		_xdr_argument = (xdrproc_t) xdr_argAchaSerie;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) acheter_serie_1_svc;
		break;

	case AJOUTER_NOTE:
		_xdr_argument = (xdrproc_t) xdr_argAjouterNote;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) ajouter_note_1_svc;
		break;

	case ACHETER_COIN:
		_xdr_argument = (xdrproc_t) xdr_argAchaCoin;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) acheter_coin_1_svc;
		break;

	case AFFICHER_COIN:
		_xdr_argument = (xdrproc_t) xdr_compte;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) afficher_coin_1_svc;
		break;

	case AJOUTER_FAVORIS:
		_xdr_argument = (xdrproc_t) xdr_argAchaSerie;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) ajouter_favoris_1_svc;
		break;

	case AFFICHER_FAVORIS:
		_xdr_argument = (xdrproc_t) xdr_compte;
		_xdr_result = (xdrproc_t) xdr_listSerie;
		local = (char *(*)(char *, struct svc_req *)) afficher_favoris_1_svc;
		break;

	case SUPPRIMER_FAVORIS:
		_xdr_argument = (xdrproc_t) xdr_argAchaSerie;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) supprimer_favoris_1_svc;
		break;

	case AJOUTER_COMMENTAIRE:
		_xdr_argument = (xdrproc_t) xdr_argAjoutComm;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) ajouter_commentaire_1_svc;
		break;

	case SUPPRIMER_COMMENTAIRE:
		_xdr_argument = (xdrproc_t) xdr_argAjoutComm;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) supprimer_commentaire_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (WEBTOON_PROG, WEBTOON_VERSION_1);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, WEBTOON_PROG, WEBTOON_VERSION_1, webtoon_prog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (WEBTOON_PROG, WEBTOON_VERSION_1, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, WEBTOON_PROG, WEBTOON_VERSION_1, webtoon_prog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (WEBTOON_PROG, WEBTOON_VERSION_1, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
