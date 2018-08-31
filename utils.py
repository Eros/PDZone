import logging
import lxml.objectify
import re


def is_ipv4(ipv4):
    re_ipv4 = re.compile('^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[09][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)')

    if re_ipv4.match(ipv4) is not None:
        return True
    return False


def normalize_rfc952(name):
    normalised = str(name).lower().strip('.')
