// Copyright (c) 2016-2018 The PaydayCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PAYDAYCOIN_WALLET_RPCWALLET_H
#define PAYDAYCOIN_WALLET_RPCWALLET_H

#include <memory>
#include <string>
#include <vector>

class CRPCTable;
class CWallet;
class JSONRPCRequest;
class UniValue;
struct PartiallySignedTransaction;
class CTransaction;

namespace interfaces {
class Chain;
class Handler;
}

void RegisterWalletRPCCommands(interfaces::Chain& chain, std::vector<std::unique_ptr<interfaces::Handler>>& handlers);
// PAYDAYCOIN
void RegisterAssetWalletRPCCommands(interfaces::Chain& chain, std::vector<std::unique_ptr<interfaces::Handler>>& handlers);
void RegisterGovernanceWalletRPCCommands(interfaces::Chain& chain, std::vector<std::unique_ptr<interfaces::Handler>>& handlers);
/**
 * Figures out what wallet, if any, to use for a JSONRPCRequest.
 *
 * @param[in] request JSONRPCRequest that wishes to access a wallet
 * @return nullptr if no wallet should be used, or a pointer to the CWallet
 */
std::shared_ptr<CWallet> GetWalletForJSONRPCRequest(const JSONRPCRequest& request);

std::string HelpRequiringPassphrase(const CWallet*);
void EnsureWalletIsUnlocked(const CWallet*);
bool EnsureWalletIsAvailable(const CWallet*, bool avoidException);

UniValue getaddressinfo(const JSONRPCRequest& request);
UniValue signrawtransactionwithwallet(const JSONRPCRequest& request);
#endif //PAYDAYCOIN_WALLET_RPCWALLET_H
