# NashCoin
A fun learning project to create the Nash blockchain and NashCoin!

## Notes

### Blockchain
A chain of data blocks that each contain the following data points:
- Data (ex: transactions)
- Magic Number (when added to the data, the hash generated is valid per global difficulty requirements)
- A timestamp
- A hash
- The hash of the previous block

### Hashing functions (Proof of Work)
- Basic one is Sha256 or some other secure hashing function

### Mining
- The starting magic number can be randomly distributed, to ensure miners start at various places.

### Functionality
The following functions should be availble:
- Generating a hash for a block
- Add new block that requires proof-of-work computational puzzle
- Validate the chain

### Proof of Work vs Proof of Stake
- Implement Proof of Work and Proof of Stake

