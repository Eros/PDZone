//
// Created by george on 31/08/18.
//

typedef std::vector <IPAdress> List

enum
{
    MAX_LENGTH = sizeof(struct in_addr)
};

//contains basic information regarding an ip address, will be used later down the line but not right away
enum family {
    IPAddress()
    IPAddress(const IPAddress& addr)
    IPAddress(const std::string& addr)
    IPAddress(const std::string &addr, Family family)
    IPAddress(const void* addr, Family family)
    IPAddress(const void* addr, poco_socklen_t length)
    IPAddress(unsigned prefix, Family family)
    IPAddress(const struct sockaddr& sockaddr)
    IPAddress& operator=(const IPAddress& addr)
    Family family() const
    Poco::UInt32 scope() const
    std::string toString() const
    bool isWildcard() const
    bool isBroadcast() const
    bool isLoopback() const
    bool isMulticast() const
    bool
    isUnicast () const

    bool isLinkLocal () const

    bool isSiteLocal () const

    bool isIPv4Compatible () const

    bool isIPv4Mapped () const

    bool isWellKnownMC () const

    bool isNodeLocalMC () const

    bool isLinkLocalMC () const

    bool isSiteLocalMC () const

    bool isOrgLocalMC () const

    bool isGlobalMC () const

    bool operator== (const IPAddress& addr) const

    bool operator!= (const IPAddress& addr) const

    bool operator< (const IPAddress& addr) const

    bool operator<= (const IPAddress& addr) const

    bool operator> (const IPAddress& addr) const

    bool operator>= (const IPAddress& addr) const

    IPAddress operator& (const IPAddress& addr) const

    IPAddress operator| (const IPAddress& addr) const

    IPAddress operator^ (const IPAddress& addr) const

    IPAddress operator~ () const

    const void* addr () const

    int af () const

    unsigned
    prefixLength () const

    void
    mask (const IPAddress& mask)

    void
    mask (const IPAddress& mask, const IPAddress& set)

    static IPAddress parse (const std::string& addr)

    static
    bool
    tryParse (
    const std::string& addr,
    IPAddress& result
    )

    static IPAddress wildcard (Family family = IPv4)

    static IPAddress broadcast ()
};
