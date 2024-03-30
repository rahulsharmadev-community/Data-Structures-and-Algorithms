def isValidEmail(email):
    if '@' not in email or '.' not in email:
        return False

    local_part, domain_part = email.split('@')

    for char in local_part:
        if not (char.isalnum() or char in '.!#$%&\'*+-/=?^_`{|}~'):
            return False
    
    if domain_part.count('.') != 1 or domain_part.startswith('.') or domain_part.endswith('.'):
        return False
    return True

inp = input("Enter you email id: ")

if(isValidEmail(inp)):
   print("Valid email id.") 
else:
    print("Invalid email id.")
     
     