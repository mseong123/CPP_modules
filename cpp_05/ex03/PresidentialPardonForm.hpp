#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm & src);
		PresidentialPardonForm & operator=(PresidentialPardonForm & src);
		void	execute(Bureaucrat const & executor) const;
};

#endif