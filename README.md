# code-CortexM-Formalization
Cortex-M Formal Verification Code

## Scenario 1

1. Set CONTROL[1] = 1

- CONTROL = 0x02 (P) or 0x03 (UP)
- Make sure we use PSP

2. Set top 8 bytes of MSP to

- Partial RETPSR = 0x00000001
- ReturnAddress = Any executable address
- Simulate top of the MSP has been manipulated

3. In the SVC handler, before calling BX, set IPSR = 1

- Make sure we stay in the handler mode using MSP
- And do not change execution mode in FNC_RETURN
- FNC_RETURN integrity check (B3.17)
