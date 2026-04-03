# Password Change Flow

1. Register and log in as `alice`.
2. Navigate to `Change Password`.
3. Submit the correct old password and a new password.
4. Confirm the status bar reports `change-password -> success`.
5. Log out.
6. Confirm the old password now fails and the new password succeeds.
7. Confirm `show-audit` contains a `PasswordChange/success` event.
